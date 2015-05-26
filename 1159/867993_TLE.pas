const maxn=5000;
var i,j,n:longint;
    f:array[0..maxn,0..maxn]of integer;
    a:array[1..maxn]of char;
begin
  //assign(input,'pku1159.in');reset(input);
  repeat
  readln(n);
  for i:=1 to n do read(a[i]);
  readln;
  for i:=0 to n do begin f[0,i]:=0;f[i,0]:=0;end;
  for i:=1 to n do
    for j:=1 to i do begin
      f[i,j]:=f[i-1,j];
      if f[i,j]<f[i,j-1] then f[i,j]:=f[i,j-1];
      if (f[i,j]<f[i-1,j-1]+1)and(a[i]=a[n-j+1]) then f[i,j]:=f[i-1,j-1]+1;
      end;
  writeln(n-f[n,n]);
until seekeof;
end.
