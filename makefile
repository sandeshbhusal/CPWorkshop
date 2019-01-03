adjacency_list: adjlist.cpp
	@g++ -o ./bin/adjlist adjlist.cpp
	@./bin/adjlist

adjacency_matrix: adjmat.cpp
	@g++ -o ./bin/adjmat adjmat.cpp
	@./bin/adjmat

map: map.cpp
	@g++ -o ./bin/map map.cpp
	@./bin/map

vector: vector.cpp
	@g++ -o ./bin/vector vector.cpp
	@./bin/vector

testcase_reader: testcase_reader.cpp
	@g++ -o ./bin/testcase_reader testcase_reader.cpp
	@./bin/testcase_reader

reroute: reroute.cpp
	@g++ -o ./bin/reroute reroute.cpp
	@./bin/reroute

auto: autokwd.cpp
	@g++ -o ./bin/auto autokwd.cpp
	@./bin/auto

compare: compare.cpp
	@g++ -o ./bin/compare compare.cpp
	@./bin/compare

twopointer: twopointer.cpp
	@g++ -o ./bin/twopointer twopointer.cpp
	@./bin/twopointer

slide: slide.cpp
	@g++ -o ./bin/slide slide.cpp
	@./bin/slide

bfs: bfs.cpp
	@g++ -o ./bin/bfs bfs.cpp
	@./bin/bfs