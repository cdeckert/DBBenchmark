class Serie
	constructor: (@computer, @disk, @test, @layout)->
		@.query()
		@.formatData()
	query: ->
		$.ajaxSetup {async: false}
		@rawData = $.getJSON("../results/#{@computer}-#{@disk}-#{@test}-#{@layout}.json").responseJSON

	formatData: ->
		@data = []
		@data.push [0, @rawData.measurements[0].duration/1000000000] if @rawData.measurements.length == 1
		@data.push [d.size/1024, d.duration/1000000000] for d in @rawData.measurements


	get: ->
		data: @data
		name: @test