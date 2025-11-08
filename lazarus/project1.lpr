program project1;

{$mode objfpc}{$H+}{$J-}

procedure MyProcedure(const A: Integer);
begin
     WriteLn('A + 10 is: ', A + 10);
end;

function MyFunction(const S: string): string;
begin
     // To return a value from a function, assign something to the magic
     // `Result` variable. You can read and set the `Result` freely
     // Just like a local variable
     Result := S + 'strings are automatically managed';
end;

var
  X: Single;

begin
     WriteLn(MyFunction('Note: '));
     MyProcedure(5);
     // Division using "/" always makes float result, use "div" for integer division
     X := 15/5;
     WriteLn('X is now: ', X);  // scientific notation
     WriteLn('X is now: ', X:1:2);  // 2 decimal places
     ReadLn()
end.



