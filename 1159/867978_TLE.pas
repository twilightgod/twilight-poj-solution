program ex;
const maxn=5001;
var len,i,j:longint;
    a,b:array[1..maxn]of char;
    s:array[boolean,0..maxn]of longint;
function max(x,y:longint):longint;
begin
 if x>y then max:=x else max:=y;
end;
begin
// assign(input,'d:\input.in');reset(input);
 repeat
  fillchar(s,sizeof(s),0);
  readln(len);
  for i:=1 to len do
   begin
    read(a[i]);
    b[len-i+1]:=a[i];
   end;
  for i:=1 to len do
   for j:=1 to len do
    begin
     s[odd(i),j]:=max(s[odd(i),j-1],s[odd(i-1),j]);
     if a[i]=b[j] then
      s[odd(i),j]:=max(s[odd(i-1),j-1]+1,s[odd(i),j]);
    end;
  writeln(len-s[odd(len),len]);
 until seekeof;
// close(input);
end.
