class Configurator

	config = null

	@get: ->
		config ?= $.getJSON("../assets/fullConfig.json").responseJSON
		config

	@getComputer: ->
		computer for computer of @get() when computer != "layouts" && computer != "tests"

	@getHdd: (computer)->
		console.log @get()[computer]
		d.replace("/dev/", "") for d in @get()[computer].disks

	@getLayouts: ->
		key for key of @get().layouts

	@getTests: ->
		console.log @get().tests
		test.name for test in @get().tests