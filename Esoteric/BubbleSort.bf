Bubble sort of all inputted values
I'm not sure how this program manages to terminate

Input values into every other cell starting at 3
0 _ i0 _ i1 _ // in _ 0
>>,[>>,]

Return to beginning 0
<<[<<]

>+
[
    -
    Start at i1
    >>>
    [
        Go from i1 to i0
        <<

        Duplicate a into d0
        0 _ a d0 b t0 c _ d _ 0
        >[-]>>[-]          ptr at t0
        <<<[>+>>+<<<-]     ptr at a
        >>>[<<<+>>>-]      ptr at t0

        Duplicate b into d1
        0 _ a d0 b d1 c t0 d _ 0
        [-]>>[-]           clear d1 and t0
        <<<[>+>>+<<<-]     ptr at b
        >>>[<<<+>>>-]      ptr at t0

        Check if a \g b
        0 _ a d0 b d1 c z d t0 e t1 f _ 0
        [-]>>[-]>>[-]<<<<
        <<<<      ptr at d0
        [
            >>>>>>+                        ptr at t0
            <<<<[- >>>>[-] >>+ <<<<<<]     ptr at d1
            >>>>[- <<+ >>]                 ptr at t0
            >>  [- <<<<<<+ >>>>>>]         ptr at t1
            <<<<<<-<<-                     ptr at d0
        ]
        [-]>>[-]

        >>    ptr at z
        [
            If a is greater than b
            -    decrement z
            <<<<<<+>>>>>>    increment check bit

            0 C a d0 b _ c z d _ e _ f _ 0
            Move a to d0
            <<<<[-]
            <[>+ <-]      ptr at a and a=0

            Move b to a
            >>[<<+>>-]    ptr at b and b=0
    
            Move d0 to b
            <[>+<-]
        ]
    <
    ]
    
    Return to beginning
    <<[<<]>
]

>[.>>]