const maxn=50000;
var i,j,n,t:longint;
    f:array[0..1,0..maxn]of longint;
    a,b:array[1..maxn]of char;
begin
  repeat
  readln(n);
  for i:=1 to n do begin
    read(a[i]);
    b[n-i+1]:=a[i];
    end;
  readln;
  f[1,0]:=0;f[1,0]:=0;f[0,0]:=0;
  for i:=1 to n do
    for j:=1 to n do begin
      t:=i mod 2;
      f[t,j]:=f[1-t,j];
      if f[t,j]<f[t,j-1] then f[t,j]:=f[t,j-1];
      if (f[t,j]<f[1-t,j-1]+1)and(a[i]=b[j]) then f[t,j]:=f[t,j-1]+1;
      end;
  writeln(n-f[t mod 2,n]);
  until seekeof;
end.
