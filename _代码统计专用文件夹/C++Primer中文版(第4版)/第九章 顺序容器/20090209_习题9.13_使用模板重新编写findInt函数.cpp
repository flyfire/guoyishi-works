//使用模板重新编写findInt函数
template<typename T1, typename T2>
T1 findValue(T1 beg, T1 end, T2 val)
{
	while (beg != end)
		if (*beg == val)
			break;
		else
			++beg;

	return beg;
}