<:Program.s:>
//apagar pantalla a los 30 segundos
baud=115200//Configure baudrate
//ussp=30
thsp=30
thup=1


<:Page0:>
<:Preinitialize:>
baud=115200
//ussp=30
thsp=30
thup=1

<:Page0.b0:>
if(page1.b0.isbr==1)
{
  page page1
}
if(page2.b0.isbr==1)
{
  page page2
}


<:Page1:>
<:Preinitialize:>
page1.b0.isbr=1
page2.b0.isbr=0

<:Page1.b0:>
page page1

<:Page1.b1:>
page page2

<:Page1.b2:>
prints "C:CCON",0
prints bt0.txt,0
prints ":",0
prints t2.txt,0
prints "?",0

<:Page1.b3:>
prints "C:CGET10?",0

<:Page1.b4:>
page page0

<:Page1.b5:>
page page0

<:Page1.b7:>
bt0.val=0
if(va0.val<va2.val)
{
  va0.val++
}else
{
  va0.val=0
}
covx va0.val,va1.txt,0,0
prints "C:CNUM",0
prints va1.txt,0
prints ":",0
prints "?",0

<:Page1.b8:>
bt0.val=0
if(va0.val>0)
{
  va0.val--
}else
{
  va0.val=va2.val
}
covx va0.val,va1.txt,0,0
prints "C:CNUM",0
prints va1.txt,0
prints ":",0
prints "?",0

<:Page1.h0:>
dims=h0.val
page2.h0.val=page1.h0.val


<:Page2:>
<:Preinitialize:>
page1.b0.isbr=0
page2.b0.isbr=1

<:Page2.b0:>
page page1

<:Page2.b1:>
page page2

<:Page2.b4:>
page page0

<:Page2.b5:>
page page0

<:Page2.h0:>
dims=h0.val
page1.h0.val=page2.h0.val