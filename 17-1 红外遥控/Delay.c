void Delay(unsigned int ms)		//@11.0592MHz
{
	while(ms--)
	{
		unsigned char i, j;
	i = 2;
	j = 239;
		do
		{
			while (--j);
		} while (--i);
	}
	
}