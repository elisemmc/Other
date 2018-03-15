Returns minimum ascii value of two inputted characters

Input two values
,>,
in0 in1

Duplicate inputs into temp values
y in1 x t0
>[-]>[-]
<<<[>>+>+<<<-]
>>>[<<<+>>>-]

in0 y d0 x t0
[-]>[-]
<<<[>>+>+<<<-]
>>>[<<<+>>>-]

in0 in1 x y z t0 t1
[-]>[-]>[-]
<<<<[>>>+
     <<[->>[-]>+<<<]
     >>[-<+>]
     >[-<<<+>>>]
     <<<-<-]

Move z=(x \g y) to position 3
in0 in1 z t0 z_old
[-]>[-]
>[<<+>>-]

Use comparison to output smaller value
in0 in1 z t0 t1
[-]<[-]+
<[<.>>-]>
[< <<.>>>->]