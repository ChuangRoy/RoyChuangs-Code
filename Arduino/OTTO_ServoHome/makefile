BOARD?=arduino:avr:nano:cpu=atmega328old
PORT?=com4

all:
	arduino-cli compile -b $(BOARD)
	arduino-cli upload -b $(BOARD) -p $(PORT)
