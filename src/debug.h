
#ifndef DEBUG_H
#define DEBUG_H

#include <sstream>
#include <string>
#include <vector>

#include "types.h",

Move* get_moves(Move *list);

namespace Debug {

// 6rk/7p/Q2R1p2/1p2n3/4b3/1P4NP/P1P2PPK/2q5 b - - 0 1
// 8/3KP3/8/8/8/8/6k1/7q b - - 0 1

inline std::string perft_suite = R"(rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1 ;D1 20 ;D2 400 ;D3 8902 ;D4 197281 ;D5 4865609 ;D6 119060324
r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 ;D1 48 ;D2 2039 ;D3 97862 ;D4 4085603 ;D5 193690690
4k3/8/8/8/8/8/8/4K2R w K - 0 1 ;D1 15 ;D2 66 ;D3 1197 ;D4 7059 ;D5 133987 ;D6 764643
4k3/8/8/8/8/8/8/R3K3 w Q - 0 1 ;D1 16 ;D2 71 ;D3 1287 ;D4 7626 ;D5 145232 ;D6 846648
4k2r/8/8/8/8/8/8/4K3 w k - 0 1 ;D1 5 ;D2 75 ;D3 459 ;D4 8290 ;D5 47635 ;D6 899442
r3k3/8/8/8/8/8/8/4K3 w q - 0 1 ;D1 5 ;D2 80 ;D3 493 ;D4 8897 ;D5 52710 ;D6 1001523
4k3/8/8/8/8/8/8/R3K2R w KQ - 0 1 ;D1 26 ;D2 112 ;D3 3189 ;D4 17945 ;D5 532933 ;D6 2788982
r3k2r/8/8/8/8/8/8/4K3 w kq - 0 1 ;D1 5 ;D2 130 ;D3 782 ;D4 22180 ;D5 118882 ;D6 3517770
8/8/8/8/8/8/6k1/4K2R w K - 0 1 ;D1 12 ;D2 38 ;D3 564 ;D4 2219 ;D5 37735 ;D6 185867
8/8/8/8/8/8/1k6/R3K3 w Q - 0 1 ;D1 15 ;D2 65 ;D3 1018 ;D4 4573 ;D5 80619 ;D6 413018
4k2r/6K1/8/8/8/8/8/8 w k - 0 1 ;D1 3 ;D2 32 ;D3 134 ;D4 2073 ;D5 10485 ;D6 179869
r3k3/1K6/8/8/8/8/8/8 w q - 0 1 ;D1 4 ;D2 49 ;D3 243 ;D4 3991 ;D5 20780 ;D6 367724
r3k2r/8/8/8/8/8/8/R3K2R w KQkq - 0 1 ;D1 26 ;D2 568 ;D3 13744 ;D4 314346 ;D5 7594526 ;D6 179862938
r3k2r/8/8/8/8/8/8/1R2K2R w Kkq - 0 1 ;D1 25 ;D2 567 ;D3 14095 ;D4 328965 ;D5 8153719 ;D6 195629489
r3k2r/8/8/8/8/8/8/2R1K2R w Kkq - 0 1 ;D1 25 ;D2 548 ;D3 13502 ;D4 312835 ;D5 7736373 ;D6 184411439
r3k2r/8/8/8/8/8/8/R3K1R1 w Qkq - 0 1 ;D1 25 ;D2 547 ;D3 13579 ;D4 316214 ;D5 7878456 ;D6 189224276
1r2k2r/8/8/8/8/8/8/R3K2R w KQk - 0 1 ;D1 26 ;D2 583 ;D3 14252 ;D4 334705 ;D5 8198901 ;D6 198328929
2r1k2r/8/8/8/8/8/8/R3K2R w KQk - 0 1 ;D1 25 ;D2 560 ;D3 13592 ;D4 317324 ;D5 7710115 ;D6 185959088
r3k1r1/8/8/8/8/8/8/R3K2R w KQq - 0 1 ;D1 25 ;D2 560 ;D3 13607 ;D4 320792 ;D5 7848606 ;D6 190755813
4k3/8/8/8/8/8/8/4K2R b K - 0 1 ;D1 5 ;D2 75 ;D3 459 ;D4 8290 ;D5 47635 ;D6 899442
4k3/8/8/8/8/8/8/R3K3 b Q - 0 1 ;D1 5 ;D2 80 ;D3 493 ;D4 8897 ;D5 52710 ;D6 1001523
4k2r/8/8/8/8/8/8/4K3 b k - 0 1 ;D1 15 ;D2 66 ;D3 1197 ;D4 7059 ;D5 133987 ;D6 764643
r3k3/8/8/8/8/8/8/4K3 b q - 0 1 ;D1 16 ;D2 71 ;D3 1287 ;D4 7626 ;D5 145232 ;D6 846648
4k3/8/8/8/8/8/8/R3K2R b KQ - 0 1 ;D1 5 ;D2 130 ;D3 782 ;D4 22180 ;D5 118882 ;D6 3517770
r3k2r/8/8/8/8/8/8/4K3 b kq - 0 1 ;D1 26 ;D2 112 ;D3 3189 ;D4 17945 ;D5 532933 ;D6 2788982
8/8/8/8/8/8/6k1/4K2R b K - 0 1 ;D1 3 ;D2 32 ;D3 134 ;D4 2073 ;D5 10485 ;D6 179869
8/8/8/8/8/8/1k6/R3K3 b Q - 0 1 ;D1 4 ;D2 49 ;D3 243 ;D4 3991 ;D5 20780 ;D6 367724
4k2r/6K1/8/8/8/8/8/8 b k - 0 1 ;D1 12 ;D2 38 ;D3 564 ;D4 2219 ;D5 37735 ;D6 185867
r3k3/1K6/8/8/8/8/8/8 b q - 0 1 ;D1 15 ;D2 65 ;D3 1018 ;D4 4573 ;D5 80619 ;D6 413018
r3k2r/8/8/8/8/8/8/R3K2R b KQkq - 0 1 ;D1 26 ;D2 568 ;D3 13744 ;D4 314346 ;D5 7594526 ;D6 179862938
r3k2r/8/8/8/8/8/8/1R2K2R b Kkq - 0 1 ;D1 26 ;D2 583 ;D3 14252 ;D4 334705 ;D5 8198901 ;D6 198328929
r3k2r/8/8/8/8/8/8/2R1K2R b Kkq - 0 1 ;D1 25 ;D2 560 ;D3 13592 ;D4 317324 ;D5 7710115 ;D6 185959088
r3k2r/8/8/8/8/8/8/R3K1R1 b Qkq - 0 1 ;D1 25 ;D2 560 ;D3 13607 ;D4 320792 ;D5 7848606 ;D6 190755813
1r2k2r/8/8/8/8/8/8/R3K2R b KQk - 0 1 ;D1 25 ;D2 567 ;D3 14095 ;D4 328965 ;D5 8153719 ;D6 195629489
2r1k2r/8/8/8/8/8/8/R3K2R b KQk - 0 1 ;D1 25 ;D2 548 ;D3 13502 ;D4 312835 ;D5 7736373 ;D6 184411439
r3k1r1/8/8/8/8/8/8/R3K2R b KQq - 0 1 ;D1 25 ;D2 547 ;D3 13579 ;D4 316214 ;D5 7878456 ;D6 189224276
8/1n4N1/2k5/8/8/5K2/1N4n1/8 w - - 0 1 ;D1 14 ;D2 195 ;D3 2760 ;D4 38675 ;D5 570726 ;D6 8107539
8/1k6/8/5N2/8/4n3/8/2K5 w - - 0 1 ;D1 11 ;D2 156 ;D3 1636 ;D4 20534 ;D5 223507 ;D6 2594412
8/8/4k3/3Nn3/3nN3/4K3/8/8 w - - 0 1 ;D1 19 ;D2 289 ;D3 4442 ;D4 73584 ;D5 1198299 ;D6 19870403
K7/8/2n5/1n6/8/8/8/k6N w - - 0 1 ;D1 3 ;D2 51 ;D3 345 ;D4 5301 ;D5 38348 ;D6 588695
k7/8/2N5/1N6/8/8/8/K6n w - - 0 1 ;D1 17 ;D2 54 ;D3 835 ;D4 5910 ;D5 92250 ;D6 688780
8/1n4N1/2k5/8/8/5K2/1N4n1/8 b - - 0 1 ;D1 15 ;D2 193 ;D3 2816 ;D4 40039 ;D5 582642 ;D6 8503277
8/1k6/8/5N2/8/4n3/8/2K5 b - - 0 1 ;D1 16 ;D2 180 ;D3 2290 ;D4 24640 ;D5 288141 ;D6 3147566
8/8/3K4/3Nn3/3nN3/4k3/8/8 b - - 0 1 ;D1 4 ;D2 68 ;D3 1118 ;D4 16199 ;D5 281190 ;D6 4405103
K7/8/2n5/1n6/8/8/8/k6N b - - 0 1 ;D1 17 ;D2 54 ;D3 835 ;D4 5910 ;D5 92250 ;D6 688780
k7/8/2N5/1N6/8/8/8/K6n b - - 0 1 ;D1 3 ;D2 51 ;D3 345 ;D4 5301 ;D5 38348 ;D6 588695
B6b/8/8/8/2K5/4k3/8/b6B w - - 0 1 ;D1 17 ;D2 278 ;D3 4607 ;D4 76778 ;D5 1320507 ;D6 22823890
8/8/1B6/7b/7k/8/2B1b3/7K w - - 0 1 ;D1 21 ;D2 316 ;D3 5744 ;D4 93338 ;D5 1713368 ;D6 28861171
k7/B7/1B6/1B6/8/8/8/K6b w - - 0 1 ;D1 21 ;D2 144 ;D3 3242 ;D4 32955 ;D5 787524 ;D6 7881673
K7/b7/1b6/1b6/8/8/8/k6B w - - 0 1 ;D1 7 ;D2 143 ;D3 1416 ;D4 31787 ;D5 310862 ;D6 7382896
B6b/8/8/8/2K5/5k2/8/b6B b - - 0 1 ;D1 6 ;D2 106 ;D3 1829 ;D4 31151 ;D5 530585 ;D6 9250746
8/8/1B6/7b/7k/8/2B1b3/7K b - - 0 1 ;D1 17 ;D2 309 ;D3 5133 ;D4 93603 ;D5 1591064 ;D6 29027891
k7/B7/1B6/1B6/8/8/8/K6b b - - 0 1 ;D1 7 ;D2 143 ;D3 1416 ;D4 31787 ;D5 310862 ;D6 7382896
K7/b7/1b6/1b6/8/8/8/k6B b - - 0 1 ;D1 21 ;D2 144 ;D3 3242 ;D4 32955 ;D5 787524 ;D6 7881673
7k/RR6/8/8/8/8/rr6/7K w - - 0 1 ;D1 19 ;D2 275 ;D3 5300 ;D4 104342 ;D5 2161211 ;D6 44956585
R6r/8/8/2K5/5k2/8/8/r6R w - - 0 1 ;D1 36 ;D2 1027 ;D3 29215 ;D4 771461 ;D5 20506480 ;D6 525169084
7k/RR6/8/8/8/8/rr6/7K b - - 0 1 ;D1 19 ;D2 275 ;D3 5300 ;D4 104342 ;D5 2161211 ;D6 44956585
R6r/8/8/2K5/5k2/8/8/r6R b - - 0 1 ;D1 36 ;D2 1027 ;D3 29227 ;D4 771368 ;D5 20521342 ;D6 524966748
6kq/8/8/8/8/8/8/7K w - - 0 1 ;D1 2 ;D2 36 ;D3 143 ;D4 3637 ;D5 14893 ;D6 391507
6KQ/8/8/8/8/8/8/7k b - - 0 1 ;D1 2 ;D2 36 ;D3 143 ;D4 3637 ;D5 14893 ;D6 391507
K7/8/8/3Q4/4q3/8/8/7k w - - 0 1 ;D1 6 ;D2 35 ;D3 495 ;D4 8349 ;D5 166741 ;D6 3370175
6qk/8/8/8/8/8/8/7K b - - 0 1 ;D1 22 ;D2 43 ;D3 1015 ;D4 4167 ;D5 105749 ;D6 419369
6KQ/8/8/8/8/8/8/7k b - - 0 1 ;D1 2 ;D2 36 ;D3 143 ;D4 3637 ;D5 14893 ;D6 391507
K7/8/8/3Q4/4q3/8/8/7k b - - 0 1 ;D1 6 ;D2 35 ;D3 495 ;D4 8349 ;D5 166741 ;D6 3370175
8/8/8/8/8/K7/P7/k7 w - - 0 1 ;D1 3 ;D2 7 ;D3 43 ;D4 199 ;D5 1347 ;D6 6249
8/8/8/8/8/7K/7P/7k w - - 0 1 ;D1 3 ;D2 7 ;D3 43 ;D4 199 ;D5 1347 ;D6 6249
K7/p7/k7/8/8/8/8/8 w - - 0 1 ;D1 1 ;D2 3 ;D3 12 ;D4 80 ;D5 342 ;D6 2343
7K/7p/7k/8/8/8/8/8 w - - 0 1 ;D1 1 ;D2 3 ;D3 12 ;D4 80 ;D5 342 ;D6 2343
8/2k1p3/3pP3/3P2K1/8/8/8/8 w - - 0 1 ;D1 7 ;D2 35 ;D3 210 ;D4 1091 ;D5 7028 ;D6 34834
8/8/8/8/8/K7/P7/k7 b - - 0 1 ;D1 1 ;D2 3 ;D3 12 ;D4 80 ;D5 342 ;D6 2343
8/8/8/8/8/7K/7P/7k b - - 0 1 ;D1 1 ;D2 3 ;D3 12 ;D4 80 ;D5 342 ;D6 2343
K7/p7/k7/8/8/8/8/8 b - - 0 1 ;D1 3 ;D2 7 ;D3 43 ;D4 199 ;D5 1347 ;D6 6249
7K/7p/7k/8/8/8/8/8 b - - 0 1 ;D1 3 ;D2 7 ;D3 43 ;D4 199 ;D5 1347 ;D6 6249
8/2k1p3/3pP3/3P2K1/8/8/8/8 b - - 0 1 ;D1 5 ;D2 35 ;D3 182 ;D4 1091 ;D5 5408 ;D6 34822
8/8/8/8/8/4k3/4P3/4K3 w - - 0 1 ;D1 2 ;D2 8 ;D3 44 ;D4 282 ;D5 1814 ;D6 11848
4k3/4p3/4K3/8/8/8/8/8 b - - 0 1 ;D1 2 ;D2 8 ;D3 44 ;D4 282 ;D5 1814 ;D6 11848
8/8/7k/7p/7P/7K/8/8 w - - 0 1 ;D1 3 ;D2 9 ;D3 57 ;D4 360 ;D5 1969 ;D6 10724
8/8/k7/p7/P7/K7/8/8 w - - 0 1 ;D1 3 ;D2 9 ;D3 57 ;D4 360 ;D5 1969 ;D6 10724
8/8/3k4/3p4/3P4/3K4/8/8 w - - 0 1 ;D1 5 ;D2 25 ;D3 180 ;D4 1294 ;D5 8296 ;D6 53138
8/3k4/3p4/8/3P4/3K4/8/8 w - - 0 1 ;D1 8 ;D2 61 ;D3 483 ;D4 3213 ;D5 23599 ;D6 157093
8/8/3k4/3p4/8/3P4/3K4/8 w - - 0 1 ;D1 8 ;D2 61 ;D3 411 ;D4 3213 ;D5 21637 ;D6 158065
k7/8/3p4/8/3P4/8/8/7K w - - 0 1 ;D1 4 ;D2 15 ;D3 90 ;D4 534 ;D5 3450 ;D6 20960
8/8/7k/7p/7P/7K/8/8 b - - 0 1 ;D1 3 ;D2 9 ;D3 57 ;D4 360 ;D5 1969 ;D6 10724
8/8/k7/p7/P7/K7/8/8 b - - 0 1 ;D1 3 ;D2 9 ;D3 57 ;D4 360 ;D5 1969 ;D6 10724
8/8/3k4/3p4/3P4/3K4/8/8 b - - 0 1 ;D1 5 ;D2 25 ;D3 180 ;D4 1294 ;D5 8296 ;D6 53138
8/3k4/3p4/8/3P4/3K4/8/8 b - - 0 1 ;D1 8 ;D2 61 ;D3 411 ;D4 3213 ;D5 21637 ;D6 158065
8/8/3k4/3p4/8/3P4/3K4/8 b - - 0 1 ;D1 8 ;D2 61 ;D3 483 ;D4 3213 ;D5 23599 ;D6 157093
k7/8/3p4/8/3P4/8/8/7K b - - 0 1 ;D1 4 ;D2 15 ;D3 89 ;D4 537 ;D5 3309 ;D6 21104
7k/3p4/8/8/3P4/8/8/K7 w - - 0 1 ;D1 4 ;D2 19 ;D3 117 ;D4 720 ;D5 4661 ;D6 32191
7k/8/8/3p4/8/8/3P4/K7 w - - 0 1 ;D1 5 ;D2 19 ;D3 116 ;D4 716 ;D5 4786 ;D6 30980
k7/8/8/7p/6P1/8/8/K7 w - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874
k7/8/7p/8/8/6P1/8/K7 w - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679
k7/8/8/6p1/7P/8/8/K7 w - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874
k7/8/6p1/8/8/7P/8/K7 w - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679
k7/8/8/3p4/4p3/8/8/7K w - - 0 1 ;D1 3 ;D2 15 ;D3 84 ;D4 573 ;D5 3013 ;D6 22886
k7/8/3p4/8/8/4P3/8/7K w - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4271 ;D6 28662
7k/3p4/8/8/3P4/8/8/K7 b - - 0 1 ;D1 5 ;D2 19 ;D3 117 ;D4 720 ;D5 5014 ;D6 32167
7k/8/8/3p4/8/8/3P4/K7 b - - 0 1 ;D1 4 ;D2 19 ;D3 117 ;D4 712 ;D5 4658 ;D6 30749
k7/8/8/7p/6P1/8/8/K7 b - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874
k7/8/7p/8/8/6P1/8/K7 b - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679
k7/8/8/6p1/7P/8/8/K7 b - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874
k7/8/6p1/8/8/7P/8/K7 b - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679
k7/8/8/3p4/4p3/8/8/7K b - - 0 1 ;D1 5 ;D2 15 ;D3 102 ;D4 569 ;D5 4337 ;D6 22579
k7/8/3p4/8/8/4P3/8/7K b - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4271 ;D6 28662
7k/8/8/p7/1P6/8/8/7K w - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874
7k/8/p7/8/8/1P6/8/7K w - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679
7k/8/8/1p6/P7/8/8/7K w - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874
7k/8/1p6/8/8/P7/8/7K w - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679
k7/7p/8/8/8/8/6P1/K7 w - - 0 1 ;D1 5 ;D2 25 ;D3 161 ;D4 1035 ;D5 7574 ;D6 55338
k7/6p1/8/8/8/8/7P/K7 w - - 0 1 ;D1 5 ;D2 25 ;D3 161 ;D4 1035 ;D5 7574 ;D6 55338
3k4/3pp3/8/8/8/8/3PP3/3K4 w - - 0 1 ;D1 7 ;D2 49 ;D3 378 ;D4 2902 ;D5 24122 ;D6 199002
7k/8/8/p7/1P6/8/8/7K b - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874
7k/8/p7/8/8/1P6/8/7K b - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679
7k/8/8/1p6/P7/8/8/7K b - - 0 1 ;D1 5 ;D2 22 ;D3 139 ;D4 877 ;D5 6112 ;D6 41874
7k/8/1p6/8/8/P7/8/7K b - - 0 1 ;D1 4 ;D2 16 ;D3 101 ;D4 637 ;D5 4354 ;D6 29679
k7/7p/8/8/8/8/6P1/K7 b - - 0 1 ;D1 5 ;D2 25 ;D3 161 ;D4 1035 ;D5 7574 ;D6 55338
k7/6p1/8/8/8/8/7P/K7 b - - 0 1 ;D1 5 ;D2 25 ;D3 161 ;D4 1035 ;D5 7574 ;D6 55338
3k4/3pp3/8/8/8/8/3PP3/3K4 b - - 0 1 ;D1 7 ;D2 49 ;D3 378 ;D4 2902 ;D5 24122 ;D6 199002
8/Pk6/8/8/8/8/6Kp/8 w - - 0 1 ;D1 11 ;D2 97 ;D3 887 ;D4 8048 ;D5 90606 ;D6 1030499
n1n5/1Pk5/8/8/8/8/5Kp1/5N1N w - - 0 1 ;D1 24 ;D2 421 ;D3 7421 ;D4 124608 ;D5 2193768 ;D6 37665329
8/PPPk4/8/8/8/8/4Kppp/8 w - - 0 1 ;D1 18 ;D2 270 ;D3 4699 ;D4 79355 ;D5 1533145 ;D6 28859283
n1n5/PPPk4/8/8/8/8/4Kppp/5N1N w - - 0 1 ;D1 24 ;D2 496 ;D3 9483 ;D4 182838 ;D5 3605103 ;D6 71179139
8/Pk6/8/8/8/8/6Kp/8 b - - 0 1 ;D1 11 ;D2 97 ;D3 887 ;D4 8048 ;D5 90606 ;D6 1030499
n1n5/1Pk5/8/8/8/8/5Kp1/5N1N b - - 0 1 ;D1 24 ;D2 421 ;D3 7421 ;D4 124608 ;D5 2193768 ;D6 37665329
8/PPPk4/8/8/8/8/4Kppp/8 b - - 0 1 ;D1 18 ;D2 270 ;D3 4699 ;D4 79355 ;D5 1533145 ;D6 28859283
n1n5/PPPk4/8/8/8/8/4Kppp/5N1N b - - 0 1 ;D1 24 ;D2 496 ;D3 9483 ;D4 182838 ;D5 3605103 ;D6 71179139
8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - 0 1 ;D4 43238 ;D5 674624 ;D6 11030083 ;D7 178633661
rnbqkb1r/ppppp1pp/7n/4Pp2/8/8/PPPP1PPP/RNBQKBNR w KQkq f6 0 1 ;D5 11139762
)";

inline std::vector<std::string> endgames =
{
    "8/p1p3pp/2k5/P1B5/1Pr3n1/5N2/r4PPP/3R2K1 w - - 2 26",
    "8/1RPk4/8/5p1p/5Pbr/4B3/5K2/8 b - - 2 42",
    "R7/P4pkp/4n1p1/3N4/8/7P/6PK/r7 b - - 2 40",
    "rn3rk1/pp3p1p/3p4/6pn/3P1p2/3B1R1P/PPP3P1/R1B3K1 w - - 0 15",
    "8/5pk1/1R2p1p1/6P1/1p2KP2/1r2P3/8/8 b - - 1 47",
    "7k/4P1np/1p6/p7/2P5/3R3P/4r1BK/8 b - - 2 48",
    "3r2k1/3Nn1pp/2b1pp2/1pNp4/3P3P/4P1P1/2n2PB1/5RK1 w - - 2 24",
    "8/5k2/4p3/1Q1p1ppp/3P4/q2KP1P1/5P1P/8 w - - 2 33",
    "6k1/6p1/2p5/p1p3P1/PrP1Pp2/1P2r3/1R3K2/1R6 w - - 3 37",
    "3n4/2r1k2p/2p1p3/N1N1Ppb1/2P5/1P5P/PB2K1P1/8 b - - 4 28",
    "r2r3k/6pp/p1b5/3p2p1/2P5/1B6/P4R1P/5RK1 w - - 0 29",
    "2b3k1/5r1p/6pP/p1Np2P1/1p1Ppr2/P7/1PPKR3/6R1 w - - 0 36",
    "8/p6p/4k3/8/1P2ppKP/2n5/1PP2P2/8 w - - 0 33",
    "4r1k1/p4p2/1ppr3p/6pP/2BB4/1P2P3/8/2K2R2 b - - 1 29",
    "8/1R6/4kp2/5p2/1P1p4/r6P/5PPK/8 w - - 0 34",
    "2br2k1/1p4p1/2p2p1p/2P1b3/1P1NB3/3RP2P/6P1/6K1 w - - 1 26",
    "r5r1/5p1k/p1ppbp2/1p2p2p/3bP1P1/1B1P1P1P/PPP1N3/1R2K2R b K - 1 19",
    "8/pkp5/2n2R2/1p2p1P1/3pPn2/PP1P1B2/1NP4r/1K6 b - - 2 43",
    "8/2p3pp/1ppkb3/6P1/1PP4P/P3K3/4B3/8 b - - 0 36",
    "r3r1k1/pp6/2pB1pp1/8/2bP4/2P2P2/6PP/2R1R1K1 w - - 2 27",
    "8/8/3Rk1p1/1pP4p/1P3PpK/6P1/8/r7 b - - 4 41",
    "3N2k1/8/1p4p1/pP3p1p/r7/P3R3/5K2/8 b - - 4 38",
    "5r1k/6p1/4P2p/8/4R3/1PB2PP1/r6P/7K b - - 0 36",
    "4r3/p1pN1pkp/3p4/5p2/1b6/PP2P1P1/2P1K2P/R7 b - - 0 24",
    "8/ppp3p1/3k1n1p/3p4/3P4/2P5/PP1N1KPP/8 w - - 2 26",
    "2r1brk1/pR6/4Pbp1/3p1pN1/7P/6B1/P7/5R1K w - - 1 27",
    "8/6k1/3p3p/6p1/2RpPr1P/5PKR/1r6/8 w - - 0 34",
    "2r2r2/ppp1Rpk1/3p2b1/3P4/PP1P3P/8/4BR2/6K1 b - a3 0 28",
    "8/4b3/3pk3/nrp1p1p1/4PpPp/3P1P1P/P2NKB2/R7 w - - 0 40",
    "7r/1pk1Rp2/2p2p2/p2p4/P1nP2Bp/2P4P/P4PP1/6K1 b - - 1 25",
    "r3rk2/pp1b2pp/2p5/1P2bp2/N7/2PB3P/P4PP1/R4RK1 w - - 1 21",
};

inline std::vector<std::string> fens =
{
    "r1bqr1k1/ppp2ppp/2pb1n2/4p3/P3P3/2NPBN2/1PP2PPP/R2Q1RK1 b - - 0 10",
    "rn1q1rk1/1bp1bpp1/1p2pn1p/p2p4/1PPP4/P4NP1/2QNPPBP/R1B2RK1 w - - 0 11",
    "r3k2r/pbppq1pp/1pn1p2n/1N3p2/2PPP3/P3BP2/1P4PP/R2QKB1R b KQkq - 4 10",
    "r1bqr1k1/pp1nbppp/2p2n2/3p4/3P4/2N2NP1/PPQBPPBP/R4RK1 w - - 0 11",
    "r1bq1rk1/1pp2ppp/pnpb4/4p3/4P3/2NP1N1P/PPP2PP1/R1BQ1RK1 b - - 4 10",
    "r2q1rk1/1ppb1ppp/4pn2/p1b5/2Pn1B2/2NP1NP1/PP3PBP/R2Q1RK1 w - - 4 11",
    "r1bqkb1r/p4ppp/p3pn2/2P5/N2p4/1Q3N2/PP1P1PPP/R1B2RK1 b kq - 1 10",
    "r1bqk2r/ppp2ppp/2n2n2/4p3/2P5/3PPNPP/PP4B1/RN1Q1RK1 b kq - 0 10",
    "r1bq1rk1/ppp2ppp/3p1n2/4p1B1/2B1P2n/2PP4/P1P2PPP/R2Q1RK1 w - - 0 11",
    "r1bqr1k1/pp1p1pp1/2pb1n1p/4p3/2BNP3/P1NP4/1PP2PPP/R1BQ1RK1 b - - 0 10",
    "r2qk2r/1p2bpp1/2p1pn1p/p2pNb2/Pn6/1P1PP1P1/1BPN1PBP/R2QK2R w KQkq - 0 11",
    "r1bqr1k1/pp3pp1/2n1pn1p/2bp4/8/2PBPNB1/PP1N1PPP/R2Q1RK1 w - - 0 11",
    "r1bqk2r/1p2bppp/p1n1pn2/8/P2P4/2NB1N2/1P3PPP/R1BQ1RK1 b kq - 0 10",
    "r1bq1rk1/1pp1ppbp/p1n3p1/8/P2Pp3/3BBN1P/1PP2PP1/R2QK2R w KQ - 0 11",
    "rnb1k2r/1p2bppp/p3pn2/8/1PB5/P3PN2/3N1PPP/R1BK3R b kq - 0 10",
    "r2qk2r/ppp2pp1/2np3p/2b5/2P1b2P/4PNP1/PP3PB1/R1BQK2R w KQkq - 0 11",
    "rnbq1rk1/pp3pp1/4pn1p/3p4/2PN3B/2Q1P3/PP3PPP/R3KB1R b KQ - 0 10",
    "r1bqr1k1/p2n1ppp/1pp1pn2/3p4/1bPP4/1PNQ1NP1/PB2PPBP/R4RK1 b - - 2 10",
    "r1bq1rk1/1pp2ppp/1bnp1n2/4p3/1pB1P3/P1N2N1P/2PP1PP1/1RBQ1RK1 w - - 0 11",
    "r1bq1rk1/pp1n1ppp/2pbpn2/3p4/2PP3P/1P2PN2/PBRN1PP1/3QKB1R b K - 6 10",
    "r1b1kb1r/ppp2pp1/2n1qn1p/8/8/2NQ2P1/PPN1PPBP/R1B1K2R b KQkq - 0 10",
    "rn1q1rk1/pbp1bpp1/1p2pn1p/3p4/2PP4/PP3NP1/1B1NPPBP/R2Q1RK1 b - - 2 10",
    "r3k2r/p1p1qppp/p2b1n2/3p1b2/3P4/1P2P2P/P2N1PP1/RNBQ1RK1 w kq - 3 11",
    "2kr1bnr/pppq1ppp/2n5/4pbN1/8/2NPB1PP/PPP2PB1/R2QK2R b KQ - 2 10",
    "r1bq1rk1/p3bpp1/1p2pn1p/2ppB3/P7/3P2P1/1PP1PPBP/RN1QR1K1 w - - 0 11",
    "r2q1rk1/1pp1ppbp/2n3p1/3n4/p5b1/P1NP1NP1/1PQ1PPBP/R1B2RK1 w - - 2 11",
    "r2q1rk1/1pp2pp1/p1npbn1p/2bNp3/P1B1P3/3P1N2/1PP1QPPP/R1B2RK1 w - - 2 11",
    "r2qkb1r/1p1n1pp1/2p1pn1p/p1PpNb2/3P4/1Q4PP/PP1NPPB1/R1B1K2R w KQkq - 1 11",
    "r2q1rk1/pbpnbppp/1p2pn2/8/P1pP4/2B2NP1/1P1NPPBP/R2Q1RK1 w - - 6 11",
    "r1bq1rk1/p1pn1pp1/1p2p2p/3n4/3P4/P1B1PN2/1PQ2PPP/R3KB1R w KQ - 0 11",
    "r1bq1rk1/1p2npbp/2np2p1/p1p1p3/Q1P5/P1NPP1P1/1P2NPBP/R1B2RK1 b - - 3 10"
};

std::string pv();
void go();
void perft(std::istringstream& args);

} // namespace Debug

#endif
