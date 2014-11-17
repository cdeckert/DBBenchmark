$.ajaxSetup({async: false});

chartOptions = {
	title:
		text: ""
	series: []
	yAxis:
		title:
			text: "Time in s"

	xAxis:
		title:
			text: "Size in MB"
}


getRun = (run) ->
	runRaw = $.getJSON("#{run}.json", drawChart)



drawChart = (test)->
	console.log test.name
	if $("##{test.name}").length > 0
		
		chartOptions.series = test.series
		console.log chartOptions.series
		$("##{test.name}").highcharts(chartOptions)


	


getSeries = (test) ->
	series = []
	for prefix in test.filePrefixes
		series.push transformSerie($.getJSON("../results/"+prefix+test.name + ".json").responseJSON)
	series
		


transformSerie = (data) ->
	serie = {}
	serie.data = []
	if data
		for d in data.measurements
			line = []
			line.push d.size/1024
			line.push d.duration/1000000000
			serie.data.push line
			serie.name = data.name
	serie



configure = (data) ->
	filePrefixes = []
	for d in data.centaurus.disks
		filePrefixes.push "centaurus-"+d.replace("/dev/", "")+"-";

	for d in data.ubuntu.disks
		filePrefixes.push "ubuntu-"+d.replace("/dev/", "")+"-";
	
	for test in data.tests
		test.filePrefixes = filePrefixes
		test.series = getSeries test

	for test in data.tests
		drawChart test






fetchConfiguration = ->
	$.getJSON("../config.json", configure);





$(document).ready ->
	
	getRun("../results/ubuntu-sdb-RawIndexScan");
	fetchConfiguration()
	#getRun("../results/centaurus-sdh-RawIndexScan");
