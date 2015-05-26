const maxn=5001;
var i,j,n:longint;t:boolean;
    f:array[boolean,0..maxn]of longint;
    a:array[1..maxn]of char;
begin
 // assign(input,'pku1159.in');reset(input);
  repeat
  readln(n);
  for i:=1 to n do read(a[i]);
  readln;
  fillchar(f,sizeof(f),0);
  for i:=1 to n do
    for j:=1 to n do begin
      t:=odd(i);
      f[t,j]:=f[not t,j];
      if f[t,j]<f[t,j-1] then f[t,j]:=f[t,j-1];
      if (f[t,j]<f[not t,j-1]+1)and(a[i]=a[n-j+1]) then f[t,j]:=f[not t,j-1]+1;
      end;
  writeln(n-f[odd(i),n]);
  until seekeof;
end.
