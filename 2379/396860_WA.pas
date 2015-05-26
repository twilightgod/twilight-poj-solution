program pku4a;
type re=array[1..1001]of longint;
var i,j,k,n,c,cc,p,t,r,cu,last:longint;
    so,ti,num:re;
procedure qsort(var a:re;l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=a[random(r-l+1)+l];
  repeat
  while a[i]<x do inc(i);
  while a[j]>x do dec(j);
  if not(i>j) then begin
    y:=so[i];so[i]:=so[j];so[j]:=y;
    y:=ti[i];ti[i]:=ti[j];ti[j]:=y;
    y:=num[i];num[i]:=num[j];num[j]:=y;
    inc(i);dec(j);
    end;
  until i>j;
  if l<j then qsort(a,l,j);
  if i<r then qsort(a,i,r);
end;
begin
  //assign(input,'a.in');reset(input);
  repeat
  readln(c,n);
  fillchar(ti,sizeof(ti),0);
  fillchar(so,sizeof(so),0);
  for i:=1 to c do
    num[i]:=i;
  for i:=1 to n do begin
    readln(cc,p,t,r);
    if r=0 then begin inc(ti[cc],1200);continue;end;
    inc(ti[cc],t);
    dec(so[cc]);
    end;
  //sort ac
  qsort(so,1,c);
  //sort same ac
  cu:=so[1];last:=1;
  for i:=2 to c+1 do
    if so[i]<>cu then begin
    if i-1-last>1 then qsort(ti,last,i-1);
    cu:=so[i];last:=i;
    end;
  //sort same time
  last:=1;
  for i:=2 to c+1 do
    if (ti[i]<>ti[last])and(so[i]<>so[last]) then begin
    if i-1-last>1 then qsort(num,last,i-1);
    last:=i;
    end;
  for i:=1 to c do
    if i<>c then write(num[i],' ') else writeln(num[i]);
  until seekeof;
end.