class Chart
	constructor: (@id, @title) ->
		@chartData = 
		{
			chart:
				zoomType: "xy"
				title:
					text: @title
			series: []
		}
		console.log JSON.stringify @chartData

	addSerie: (serie)->
		@chartData.series.push serie.get()
		console.log @chartData

	getChartData: ->
		@chartData



	draw: ->
		console.log "THE CHART: "+ JSON.stringify @.getChartData()
		console.log $("##{@id}")
		$("##{@id}").highcharts @.getChartData()
