const maxn=5000;
var i,j,n,t:longint;
    f:array[0..1,0..maxn]of integer;
    a:array[1..maxn]of char;
begin
  assign(input,'pku1159.in');reset(input);
  repeat
  readln(n);
  for i:=1 to n do read(a[i]);
  readln;
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=1 to i do
     begin
      t:=i mod 2;
      f[t,j]:=f[1-t,j];
      if f[t,j]<f[t,j-1] then f[t,j]:=f[t,j-1];
      if (f[t,j]<f[1-t,j-1]+1)and(a[i]=a[n-j+1]) then f[t,j]:=f[1-t,j-1]+1;
     end;
  writeln(n-f[n mod 2,n]);
  until seekeof;
end.
