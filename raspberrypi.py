# 8.1D
from smbus import SMBus

addr = 0x8 # bus address
bus = SMBus(1) # indicates /dev/ic2-1

numb = 1

print ("Enter 1 for Blue or 2 for Green or 3 for Red or 0 for OFF")
while numb == 1:

	ledstate = input(">>>>   ")

	if ledstate == "1":
		bus.write_byte(addr, 0x1) # switch it on
	elif ledstate == "0":
		bus.write_byte(addr, 0x0) # switch it on
	elif ledstate == "2":
		bus.write_byte(addr, 0x2) # switch it on
	elif ledstate == "3":
		bus.write_byte(addr, 0x3) # switch it on
	else:
		numb = 0
