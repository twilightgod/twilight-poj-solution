program pku4k;
var a,b,c:array[1..81]of integer;
    i,j,k,la,lb:longint;
    s1,s2:string;
begin
  repeat
  readln(s1);
  readln(s2);
  la:=length(s1);
  lb:=length(s2);
  for i:=1 to la do
    a[i]:=ord(s1[la-i+1])-48;
  for i:=1 to lb do
    b[i]:=ord(s2[lb-i+1])-48;
  fillchar(c,sizeof(c),0);
  for i:=1 to la do
    for j:=1 to lb do
      c[i+j-1]:=c[i+j-1]+a[i]*b[j];
  for i:=1 to la+lb do
    if c[i]>9 then begin
      c[i+1]:=c[i+1]+c[i] div 10;
      c[i]:=c[i] mod 10;
      end;
  for i:=la+lb downto 1 do
    if c[i]<>0 then break;
  for j:=i downto 1 do
    write(c[j]);
  writeln;
  until seekeof;
end.
