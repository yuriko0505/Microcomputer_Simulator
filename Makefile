PIO = ~/.platformio/penv/bin/pio
DIA_DIR = diagrams
TARGETS = led tact buz time ldr pir

# pio実行
$(TARGETS) : write_main
	./write_main $@
	$(PIO) run
	cp $(DIA_DIR)/diagram_$@.txt diagram.json

# オブジェクトファイル作成
write_main : write_main.cpp
	g++ -std=c++11 -o $@ $<