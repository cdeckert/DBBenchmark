class SelectList extends EventEmitter
	constructor: (@id, @multiple = false, @values) ->		
		@.render()
		@.setEventHandler()


	setEventHandler: ->
		$("##{@id} a").on "click", @.clickHandler

	clickHandler: (event)=>
		if !@multiple
			$(event.target).parent().children().removeClass "active"
		if !$(event.target).hasClass "active"
			$(event.target).addClass "active"
		else
			$(event.target).removeClass "active"
		event.preventDefault()

	getValue: ->
		if $("##{@id} a.active").length == 1
			$("##{@id} a.active").text()
		else
			getValues()
			
	getValues: ->
		for element in $ "##{@id}"
			if $(element).hasClass "active"
				$(element).text()
			else

	render: ->
		html = ""
		for e in @values
			html += "<a class='list-group-item' href='#'>#{e}</a>"
		$("##{@id}").html html


