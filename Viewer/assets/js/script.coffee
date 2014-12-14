

start = ->
	#centaurus-sdf-FullTableScan-ordered-16kb-Page
	s = new Serie("centaurus", "sdf", "FullTableScan", "unordered-16kb-Page")
	a = new Serie("centaurus", "sdf", "RawIndexScan", "unordered-16kb-Page")
	console.log s.get()
	c = new Chart("c1", "abc", s, a)

	c.draw()


$(document).ready start