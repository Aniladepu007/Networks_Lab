#set x "hello world"
set x 10
puts $x
puts "aaa"
set x [expr $x+2]
puts $x

if {$x == 12} {
puts "hello"
return $x
} else {
puts "world"
return $x
}
