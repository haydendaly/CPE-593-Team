/* I pledge my Honor that I have abided by the Stevens Honor System. James Lawrence. */

#include<iostream>
#include<stdlib.h>
#include <bits/stdc++.h>

struct Point {
	int x, y;
};

Point getTopLeft(int arr[4]){
	return {arr[0], arr[1]};
}

Point getBottomRight(int arr[4]){
	return {arr[0]+arr[2], arr[1]+arr[3]};
}

bool doesOverlap(Point r1_top_left, Point r1_bottom_right, Point r2_top_left, Point r2_bottom_right)
{
    // Rectangle 1 area
    int area1 = std::abs(r1_top_left.x - r1_bottom_right.x) * std::abs(r1_top_left.y - r1_bottom_right.y);
    std::cout << area1 << std::endl;
 
    // Rectangle 2 area
    int area2 = std::abs(r2_top_left.x - r2_bottom_right.x) * std::abs(r2_top_left.y - r2_bottom_right.y);
    std::cout << area2 << std::endl;
 
    // Intersection length
    int Iarea = (std::min(r1_bottom_right.x, r2_bottom_right.x)-1 - std::max(r1_top_left.x, r2_top_left.x))
                * (std::max(r1_bottom_right.y, r2_bottom_right.y)-1 - std::min(r1_top_left.y, r2_top_left.y));
    std::cout << Iarea << std::endl;
 
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
    //Point r2_top_left = getTopLeft(rC), r2_bottom_right = getBottomRight(rC);
    //Point r1_top_left = { 2, -2 }, r1_bottom_right = { 5, -7 };
    //Point r2_top_left = { 3, -4 }, r2_bottom_right = { 6, -9 };

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