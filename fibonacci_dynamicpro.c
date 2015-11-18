f=0;
g=1;
while(0 < n--)
{
 g=g+f;//g升高一项
 f=g-f;//f升高一项，成为原来的g
}
return g;