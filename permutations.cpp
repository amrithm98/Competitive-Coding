#include<iostream>
#include<vector>

void swap(int& a, int& b)
{ int x=a;
  a=b;
  b=x;
}

void printVector(std::vector<int>& theVector)
{ for (unsigned int i=0; i<theVector.size(); i++)
    std::cout << theVector[i] << ",";
  std::cout << "\n";
}

void generateAllPermutations(std::vector<int> & toBePermuted, unsigned int nextIndex)
{ if (nextIndex==toBePermuted.size())
  { printVector(toBePermuted);
    return;
  }
  for (unsigned int i=nextIndex; i<toBePermuted.size(); i++)
  { swap(toBePermuted[i], toBePermuted[nextIndex]);
    generateAllPermutations(toBePermuted, nextIndex+1);
    swap(toBePermuted[i], toBePermuted[nextIndex]);
  }
}

void generateAllPermutations(std::vector<int>& toBePermuted)
{ 
    generateAllPermutations(toBePermuted, 0);
}

int main()
{ std::vector<int> theVector;

  theVector.push_back(4);
  theVector.push_back(3);
  theVector.push_back(2);
  generateAllPermutations(theVector);
  int x;
  std::cin >> x;
}
