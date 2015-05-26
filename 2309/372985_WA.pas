program pku2309;
var i,j,k,n,min,max:cardinal;
procedure seek(t:cardinal;d:byte;la:byte);
var k:cardinal;
begin
  k:=1shl la;
  if d=0 then
  if n<t then seek(t-k,d,la-1) else
  if n>t then seek(t+k,d,la-1) else
  begin
    seek(t-k,1,la-1);
    seek(t+k,2,la-1);
  end;
  if d=1 then
    if odd(t) then begin min:=t;exit;end else
    seek(t-k,1,la-1);
  if d=2 then
    if odd(t) then begin max:=t;exit;end else
    seek(t+k,2,la-1);
end;
begin
  repeat
  readln(n);
  if odd(n) then writeln(n,' ',n) else begin
  seek(1shl 30,0,29);
  writeln(min,' ',max);end;
  until seekeof;
end.