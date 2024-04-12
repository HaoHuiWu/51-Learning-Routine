void Delay(unsigned int ms)		//@11.0592MHz
{
	while(ms--)
	{
		unsigned char i, j;
	i = 2;
	j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
	
}