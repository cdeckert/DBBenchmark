class Chart
	constructor: (@id, @title, @series...) ->

	getChartData: ->
		chart:
			 zoomType: "xy"
		title:
			text: @title
		series: @series



	draw: ->
		console.log JSON.stringify @.getChartData()
		$("##{@id}").highcharts @.getChartData()
