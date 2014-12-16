class ChartManager
	constructor: ->
		@currentChart = new Chart("currentChart", "Noch kein Name vergeben")
		@currentChart.draw()
	addSerie: (@serieConfig)->
		aSerie = new Serie @serieConfig.computer, @serieConfig.hdd, @serieConfig.test, @serieConfig.layout
		aSerie.color = Highcharts.getOptions().colors[@currentChart.chartData.series.length]
		@currentChart.addSerie aSerie
		@currentChart.draw()
		
