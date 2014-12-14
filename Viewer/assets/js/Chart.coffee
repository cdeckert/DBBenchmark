class Chart
	constructor: (@id, @title, @series...) ->

	getChartData: ->
		chartData:
			title: @title
		series: @series



	draw: ->
		$("##{@id}").highcharts @.getChartData()
