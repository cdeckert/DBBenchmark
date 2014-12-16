
selectCallBack = ->
	@.getValue()


class SelectListManager
	constructor: ->
		@config = Configurator.get()
		console.log @config
		@.run()
	run: ->
		@.initSelectLists()

		$("#computer a").on "click", =>
			@.hddInit()

	initSelectLists: ->
		@.initComputer()
		@.initLayout()
		@.initTest()



	initComputer: ->
		@computerSelect = new SelectList "computer", false, Configurator.getComputer()

	hddInit: =>
		console.log @computerSelect.getValue()
		@selectedComputer = @computerSelect.getValue()
		@hddSelect = new SelectList "hdd", false, Configurator.getHdd @selectedComputer
		

	initLayout: ->

		@layoutSelect = new SelectList "layout", false, Configurator.getLayouts()

	initTest: ->
		@testSelect = new SelectList "test", false, Configurator.getTests()


	getValues: ->
		computer: @computerSelect.getValue()
		hdd: @hddSelect.getValue()
		layout: @layoutSelect.getValue()
		test: @testSelect.getValue()

