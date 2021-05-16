#include <stdio.h> 

union test { 
	int x; 
	char y; 
}; 

int main() 
{ 
	union test p1; 
	p1.x = 65; 

	// p2 is a pointer to union p1 
	union test* p2 = &p1; 

	// Accessing union members using pointer 
	printf("%c %d", p2->x, p2->y); 
	return 0; 
} 
