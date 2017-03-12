--yield return the arguments to caller
co = coroutine.create(function(a,b)
  coroutine.yield(a + b, a - b)
  end)
--the first return arguments is boolean, indicate errors
--the followed is what pass to coroutine.yield
print(coroutine.resume(co, 20, 10))

--yield return what pass to coroutine.resume
co = coroutine.create(function(x)
  print("co1", x)
  print("co2", coroutine.yield())
  end)

coroutine.resume(co, "hi")
--arguments will be returned by coroutine.yield
coroutine.resume(co, 4, 5)

--the normal return arguments will
--return to coroutine.resume
co = coroutine.create(function()
  return 6,7
  end)

--return true 6 7
print(coroutine.resume(co))

--base-
--create suspended
co = coroutine.create(function() print("hi") end)
print(co)
print(coroutine.status(co))
--start run
coroutine.resume(co)
--dead
print(coroutine.status(co))
