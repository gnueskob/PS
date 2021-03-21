// https://www.acmicpc.net/problem/6549
#include "_fileRead.hpp"
GNUES::FileRead f("6549.txt");

#include <iostream>
#include <stack>
int main()
{
	while (true)
	{
		int n;
		std::cin >> n;
		if (n == 0)
			break;

		long long max = 0;
		std::stack<std::pair<long long, int>> stk;

		for (int idx=0; idx<n; ++idx)
		{
			int height;
			std::cin >> height;

			bool new_stack = true;
			int prev_stack_idx = idx;
			// 스택에 높이가 증가하는 순서대로 쌓이게끔 한다.
			if (stk.empty() == false)
			{
				// 스택 top 높이 이하가 들어오면 다음에 쌓이는 요소들도 최대 높이에 제한이 걸림
				// 때문에 스택에 쌓인 요소중 더 높이가 높은 것들은 지우고 최대 높이를 갱신함
				// 현재 top이 직전까지 쌓여있는 것들 중 가장 높은 요소
				while (stk.empty() == false)
				{
					auto& [prev_height, prev_idx] = stk.top();
					if (prev_height <= height)
					{
						// 같은 높이까지의 넓이 갱신은 안해줘도 무방
						// 같은 높이를 가진 요소가 있다면 바로 사용하면됨
						new_stack = (prev_height != height);
						break;
					}

					// 자기보다 큰 요소들중 가장 작은 것의 위치로
					prev_stack_idx = prev_idx;

					// 삭제할 스택 요소들 대상으로 최대 넓이 갱신
					// 현재 추가하는 요소 직전의 위치와 마지막 스택으로 쌓인
					// 최대 높이 요소로 이루어진 직사각형
					max = std::max(max, prev_height * (idx - prev_idx));
					stk.pop();
				}
			}

			if (new_stack)
				stk.emplace(height, prev_stack_idx);
		}

		// 남은 스택 처리
		while (stk.empty() == false)
		{
			auto [prev_height, prev_idx] = stk.top();
			stk.pop();

			// n th 까지 늘어나는 직사각형을 만들 수 있음
			max = std::max(max, prev_height * (n - prev_idx));
		}

		std::cout << max << '\n';
	}
}