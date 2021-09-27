; A boot sector program that loops forever

; An infinite loop. Program will always
; jump back to loop.
loop:
    jmp loop

; We need to fill 512 bytes total. Last
; two bytes used to define this sector as
; a boot sector.

; Fill 510 - program size bytes
; Program size is current location $ minus
; Start location $$
; db 0 means fill with zeros
times 510 - ($ - $$) db 0

; This value at the end of the 512 byte  
; sector indicate it is a boot sector
dw 0xaa55