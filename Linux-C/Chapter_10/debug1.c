typedef struct 
{
	char *data;
	int key;
}item;

item array[] = { {"bill",1},{"Bob",3},{"Tom",7},{"Alex",5},{"Jim",4}};
sort(a,n)
item *a;
{
	int i =0 , j=0;
	int s = 1;
			
	for(;i < n && s != 0;i++)
	{
		s = 0;
		for(j = 0;j<n;j++)
		{
			if(a[j].key > a[j+1].key)
			{
				item t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
				s++;
			}
		}
		n--;
	}
}
main()
{
	sort(array,5);
}




