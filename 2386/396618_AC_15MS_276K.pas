program pku_4h;
const w:array[1..8,1..2]of shortint=((-1,0),(-1,1),(0,1),(1,1),(1,0),(1,-1),(0,-1),(-1,-1));
var i,j,k,n,m,total:longint;c:char;
    map:array[0..101,0..101]of boolean;
procedure dfs(x,y:longint);
var i,ii,jj:longint;
begin
  map[x,y]:=false;
  for i:=1 to 8 do begin
    ii:=x+w[i,1];jj:=y+w[i,2];
    if map[ii,jj] then dfs(ii,jj);
    end;
end;
begin
  //assign(input,'h.in');reset(input);
  repeat
  readln(n,m);
  fillchar(map,sizeof(map),false);total:=0;
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(c);if c='W' then map[i,j]:=true;end;
      readln;end;
  for i:=1 to n do
    for j:=1 to m do
      if map[i,j] then begin inc(total);dfs(i,j);end;
  writeln(total);
  until seekeof;
end.