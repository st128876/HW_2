#include <iostream>
#include <vector>
#include <string>

class TextEditor
{
private:
	std::vector<char> left_string;
	std::vector<char> right_string;
	int point_of_cursor = 0;



public:
	TextEditor(){}

	void addText(std::string text)
	{
		for (char s : text)
		{
			right_string.push_back(s);
		}
	}

	int deleteText(int k)
	{
		for (char s : left_string)
		{
			std::cout << s;
		}
		std::cout << "" << std::endl;
		if (k < left_string.size())
		{
			for (int i = 0; i < k; i++)
			{
				left_string.pop_back();
			}
		}
		return k;
	}

	void change_position_of_cursor(int k)
	{
		if (k < (left_string.size() + right_string.size()))
		{
			point_of_cursor = k;
			if (k < left_string.size())
			{
				int prom = left_string.size() - k;
				for (int i = 0; i < prom; i++)
				{
					right_string.insert(right_string.begin(), left_string.back());
					left_string.erase(left_string.end() - 1);
				}
			}
			else if (k > left_string.size())
			{
				//std::cout << "naaa" << std::endl;
				int prom = (k - left_string.size());
				for (int i = 0; i < prom; i++)
				{
					//std::cout << i << std::endl;
					left_string.push_back(right_string[0]);
					right_string.erase(right_string.begin());
				}
			}
		}
	} 

	void print()
	{
		for (char s : left_string)
		{
			std::cout << s;
		}
		for (char s : right_string)
		{
			std::cout << s;
		}
		std::cout << "" << std::endl;
	}


	std::string cursorLeft(int k)
	{
		this->change_position_of_cursor(point_of_cursor + k);
		std::string answer;
		for (char s : left_string)
		{
			answer += s;
		}
		std::cout << answer << std::endl;
		return answer;
	}

	std::string cursorRight(int k)
	{
		this->change_position_of_cursor(point_of_cursor - k);
		std::string answer;
		for (char s : right_string)
		{
			answer += s;
		}
		std::cout << answer << std::endl;
		return answer;
	}


};


int main()
{
	return EXIT_SUCCESS;
}