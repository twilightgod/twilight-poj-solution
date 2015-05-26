program pku4j;
var i,j,k,n:longint;
    a:array[1..10000]of longint;
procedure qsort(l,r:longint);
var i,j,x,y:longint;
begin
  i:=l;j:=r;
  x:=a[random(r-l+1)+l];
  repeat
  while a[i]<x do inc(i);
  while a[j]>x do dec(j);
  if not(i>j) then begin
    y:=a[i];a[i]:=a[j];a[j]:=y;
    inc(i);dec(j);
    end;
  until i>j;
  if l<j then qsort(l,j);
  if i<r then qsort(i,r);
end;
begin
  repeat
  readln(n);
  for i:=1 to n do
    readln(a[i]);
  qsort(1,n);
  writeln(a[n shr 1+1]);
  until seekeof;
end.