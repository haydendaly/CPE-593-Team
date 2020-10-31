/* I pledge my Honor that I have abided by the Stevens Honor System. James Lawrence. */

#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>

struct Point {
	int x, y;
};

Point getTopLeft(int arr[4]){
	return {arr[0], -arr[1]};
}

Point getBottomRight(int arr[4]){
	return {arr[0]+arr[2], -arr[1]-arr[3]};
}

/*
bool doesOverlap(Point r1_top_left, Point r1_bottom_right, Point r2_top_left, Point r2_bottom_right) {
	// check left
	if (r1_top_left.x >= r2_bottom_right.x || r2_top_left.x >= r1_bottom_right.x)
		return false;

	// check above
	if (r1_top_left.y <= r2_bottom_right.y || r2_top_left.y <= r1_bottom_right.y)
		return false;

	return true;
}
*/

bool doesOverlap(Point r1_top_left, Point r1_bottom_right, Point r2_top_left, Point r2_bottom_right)
{
    // Area of Rectangle 1
    int area1 = std::abs(r1_top_left.x - r1_bottom_right.x) * std::abs(r1_top_left.y - r1_bottom_right.y);
    std::cout << area1 << std::endl;
 
    // Area of Rectangle 2
    int area2 = std::abs(r2_top_left.x - r2_bottom_right.x) * std::abs(r2_top_left.y - r2_bottom_right.y);
    std::cout << area2 << std::endl;
 
    // Length of intersection
    int Iarea = (std::min(r1_bottom_right.x, r2_bottom_right.x) - std::max(r1_top_left.x, r2_top_left.x))
                * (std::min(std::abs(r1_bottom_right.y), std::abs(r2_bottom_right.y)) - std::max(std::abs(r1_top_left.y), std::abs(r2_top_left.y)));
 
    int overlapArea = area1 + area2 - Iarea;
    std::cout << overlapArea << std::endl;

    if ( (area1+area2) != overlapArea)
    	return true;
    else
    	return false;
}

int main(int argc, char *argv[]) {

	int rA[4] = {5,5,6,3};
	int rB[4] = {4,4,2,1};
	int rC[4] = {3,1,3,2};
	int rD[4] = {10,3,3,3};

    Point r1_top_left = getTopLeft(rA), r1_bottom_right = getBottomRight(rA);
    Point r2_top_left = getTopLeft(rD), r2_bottom_right = getBottomRight(rD);
    
    std::cout << r1_top_left.x << std::endl;
    std::cout << r1_top_left.y << std::endl << std::endl;
    std::cout << r1_bottom_right.x << std::endl;
    std::cout << r1_bottom_right.y << std::endl << std::endl;
    std::cout << r2_top_left.x << std::endl;
    std::cout << r2_top_left.y << std::endl << std::endl;
    std::cout << r2_bottom_right.x << std::endl;
    std::cout << r2_bottom_right.y << std::endl << std::endl;

    if (doesOverlap(r1_top_left, r1_bottom_right, r2_top_left, r2_bottom_right)) 
        std::cout << "Rectangles Do Overlap" << std::endl;
    else
        std::cout << "Rectangles Don't Overlap" << std::endl;
    return 0;
}