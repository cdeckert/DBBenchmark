

start = ->
	#ubuntu-sdb-FullTableScan-unordered
	unorderedStandard = new Serie "auriga", "sdb", "FullTableScan", "unordered", "column"
	unordered2xRel = new Serie "auriga", "sdb", "FullTableScan", "unordered-2x-rel", "column"
	unordered16kb = new Serie "auriga", "sdb", "FullTableScan", "unordered-16kb-Page", "column"
	unordered16kb4PpE = new Serie "auriga", "sdb", "FullTableScan", "unordered-2x-rel-16kb-4-PpE", "column"
	c = new Chart "c1", "abc", unorderedStandard.get(), unordered2xRel.get(), unordered16kb.get(), unordered16kb4PpE.get()

	c.draw()


$(document).ready start