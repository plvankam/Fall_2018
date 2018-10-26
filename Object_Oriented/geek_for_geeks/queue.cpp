// empty() – Returns whether the queue is empty
// size() – Returns the size of the queue
// front() – Returns a reference to the first element of the queue
// back() – Returns a reference to the last element of the queue
// push(g) – Adds the element ‘g’ at the end of the queue
// pop() – Deletes the first element of the queue
 
#include<iostream>
#include<queue>

void showq(std::queue<int> gq)
{
	std::queue<int> g = gq;
	while(!g.empty())
	{
		std::cout << '\t' << g.front();
		g.pop();
	}
	std::cout << std::endl;
}

int main()
{

	std::queue<int> gquiz;
	gquiz.push(10);
	gquiz.push(20);
	gquiz.push(30);

	std::cout << "The queue gquiz is : ";
	showq(gquiz);

	std::cout << "\ngquiz.size() : " << gquiz.size(); 
    std::cout << "\ngquiz.front() : " << gquiz.front(); 
    std::cout << "\ngquiz.back() : " << gquiz.back(); 

    std::cout << "\ngquiz.pop() : "; 
    gquiz.pop(); 
    showq(gquiz);

	return 0;
}
