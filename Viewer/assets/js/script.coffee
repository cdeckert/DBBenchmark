$.ajaxSetup({async: false})
theChart = null
chartManager = null
start = ->
	
	selectListManager = new SelectListManager()
	chartManager = new ChartManager()
	$("#addBtn").on "click", ->
		chartManager.addSerie selectListManager.getValues()
		console.log "click"
		theChart = chartManager


$(document).ready start