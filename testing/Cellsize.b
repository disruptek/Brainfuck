
// Calculate (16*16*16*16)^128 AKA 2^2048
++[>++++++++<-]>[>++++++++<-]>[<<
+>>[-<<
    [->++++++++++++++++<]>[-<++++++++++++++++>]<
    [->++++++++++++++++<]>[-<++++++++++++++++>]<
>>]]<+<

// If that's not zero we have a bignum; probably
[
    // Calculate 2^112 this is too large for any floating point type
    // to treat as an integer
    [-]>[-]>[-]+++++++<<
    +>>[-<<
	[->++++++++++++++++<]>[-<++++++++++++++++>]<
	[->++++++++++++++++<]>[-<++++++++++++++++>]<
    >>]<<

    // If X and X minus one are the same we have a float type
    [->+>+<<] >>- [-<->] +<

    [[-]>

    // Unknown or huge cell size
    >>>>>[-]<[-]<[-]<[-]<[-]<[-]>++++++[<++++>-]<[>+++++>++++>+>++>+
    ++<<<<<-]>>>>>.<<<<---.>+++++++.--.>++++++++.<<------.+++.>>.<<-
    ---.+.-.>>>---.<<---.+++++++.<.>--------.<++++.+++++++.>>.<++.++
    .<-------------..+++++++.>>.<+.<----.++++++.-------.>--.>>+.>[-]
    <[-]<[-]<[-]<[-]<

    <]
    >[

    // Floating point cells found
    >>>>[-]<[-]<[-]<[-]<[-]>++++[<++++>-]<[>++++>+++++++>++++++>++<<
    <<-]>++++++.>----.+++.>+.<+++++.>++++++++.+++++.-------.>.<<----
    .-.>++.<-.++++++.>>.<------.++.+++++++..<-.>>.<------.<----.++++
    ++.-------.>--.>++++++++++++++.[-]<[-]<[-]<[-]<

    ]<

    // Check for a compile problem
    >[-]+++++[<++++++>-]<++ >+<[->[->++<]>[-<+>]<<]
    #
    >>+<[[-]>-<]>[
	>[-]<[-]>++++++++[<++++>-]<.>++++++[<++++++>-]<+.+++++++++++
	++..---.+++.[-]
    ]<<
#
<[-]]
>[>
    // The cell is a binary type less than 2^2048; find exactly how
    // many bits it is
    >+[ [->++<]>[-<+>]<<+> ]<

    // and print it
    >>++++[<++++>-]<+[>++++++>+++++++>++>+++++<<<<-]>>>>-.<<<++.+.>-
    ---.>--.<<.+++++.>+.<---------.>--.--.++.<.>++.<.>--.>.<<+++.---
    ----.>+.>.>[-]<[-]<[-]<[-]<<

    >[-]>[-]>[-]>[-]>[-]>[-]+>[-]+>[-]+>[-]+<<<<<<<<<[->>+>+<<<]>>>[
    -<<<+>>>]<[>[-]>[-]<<[>+>+<<-]>>[<<+>>-]+++++++++<[>>>[-]+<<[>+>
    [-]<<-]>[<+>-]>[<<++++++++++>>-]<<-<-]+++++++++>[<->-]<[>+<-]<[>
    +<-]<[>+<-]>>>[<<<+>>>-]>>>[-]<<<+++++++++<[>>>[-]+<<[>+>[-]<<-]
    >[<+>-]>[<<++++++++++>>>+<-]<<-<-]>>>>[<<<<+>>>>-]<<<[-]<<+>]<[>
    [-]<[>+<-]+++++++[<+++++++>-]<-.[-]>>[<<+>>-]<<-]<

    >>>[-]<[-]<[-]<[-]>++++[<++++>-]<[>++++++>+++++++>++<<<-]>++.+++
    ++++.>++++.>.<<------.++.+++++++..>-.>++++++++++++++.[-]<[-]<[-]
    <

<[-]]<

[-]++++++++++.[-]
