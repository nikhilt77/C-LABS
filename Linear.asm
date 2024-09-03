        START   1000
        LDX     ZERO            ; Initialize index register to 0
        LDA     KEY             ; Load the search key into the accumulator
SEARCH  COMP    ARRAY, X        ; Compare key with current array element
        JEQ     FOUND           ; If equal, key is found, jump to FOUND
        TIXR    SIZE            ; Increment index and compare with array size
        JLT     SEARCH          ; If not end of array, repeat search
        LDA     NEG_ONE         ; If key is not found, load -1
        STA     RESULT          ; Store -1 in RESULT to indicate failure
        J       END_PROG        ; Jump to end of program

FOUND   LDA     X               ; Load the index where the key was found
        STA     RESULT          ; Store the index in RESULT

END_PROG
        END

ARRAY   WORD    5, 7, 9, 12, 15 ; Example array
KEY     WORD    12              ; Key to search for
SIZE    WORD    5               ; Size of the array
RESULT  RESW    1               ; Result (index of the key or -1)
ZERO    WORD    0               ; Constant zero
NEG_ONE WORD    -1              ; Constant -1
