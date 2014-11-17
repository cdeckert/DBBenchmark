chartOptions = {
	title:
		text: "chart"
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



drawChart = (data)->
	console.log data
	dataPoints = []
	for d in data.measurements
		dataPoint = []
		dataPoint.push d.size/1024
		dataPoint.push d.duration/1000000000
		
		dataPoints.push dataPoint
	
	serie =
		name : data.name
		data: dataPoints

	chartOptions.series.push serie


	$('#container').highcharts(chartOptions);


configure = (data) ->
	filePrefixes = []
	for d in data.centaurus.disks
		filePrefixes.push "centaurus-"+d+"-";

fetchConfiguration = ->
	$.getJSON("../config.json", configure);





$(document).ready ->
	
	getRun("../results/ubuntu-sdb-RawIndexScan");
	#getRun("../results/centaurus-sdh-RawIndexScan");
