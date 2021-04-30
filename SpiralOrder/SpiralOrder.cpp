// SpiralOrder.cpp : Defines the entry point for the application.
//

#include "SpiralOrder.h"


using namespace std;

static vector<int> spiralOrder(vector<vector<int>>& matrix);

int main()
{
	vector<vector<int>> input{ {1,2,3}, {4,5,6}, {7,8,9} };
	vector<int> expectedOut{ 1,2,3,6,9,8,7,4,5 };

	vector<int> output = spiralOrder(input);
	
	if (output != expectedOut)
	{
		cout << "output does not match" << endl;
		return 1;
	}
				
	cout<< "Output matches" <<endl;
	return 0;
}

static vector<int> spiralOrder(vector<vector<int>>& matrix) {
	vector<int> res;
	int d = 0; //0->right, 1->down, 2->left, 3->up
	int i = 0, j = 0, count = 0;
	int m_max, m_min, n_max, n_min;
	m_max = matrix.size();
	n_max = matrix[0].size();
	m_min = 1; n_min = 0;
	int total = m_max * n_max;

	while (count < total)
	{
		res.push_back(matrix[i][j]);
		count++;
		switch (d)
		{
		case 0:
			if (j == n_max - 1)
			{
				i++;
				d = 1;
				n_max -= 1;
			}
			else
			{
				j++;
			}
			break;
		case 1:
			if (i == m_max - 1)
			{
				j--;
				d = 2;
				m_max -= 1;
			}
			else
			{
				i++;
			}
			break;
		case 2:
			if (j == n_min)
			{
				i--;
				d = 3;
				n_min += 1;
			}
			else
			{
				j--;
			}
			break;
		case 3:
			if (i == m_min)
			{
				j++;
				d = 0;
				m_min += 1;
			}
			else
			{
				i--;
			}
			break;
		}
	}
	return res;

}
