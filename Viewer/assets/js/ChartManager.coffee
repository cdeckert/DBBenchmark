class ChartManager
	constructor: ->
		@currentChart = new Chart("currentChart", "Noch kein Name vergeben")
	addSerie: (@serieConfig)->
		aSerie = new Serie @serieConfig.computer, @serieConfig.hdd, @serieConfig.test, @serieConfig.layout
		console.log aSerie
		@currentChart.addSerie aSerie
		@currentChart.draw()
		
