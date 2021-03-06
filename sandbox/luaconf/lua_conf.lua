if os.isadmin() then
  print "I'm admin"
else
  print "I'm NOT admin"
end

if os.iswow64() then
  print "I'm a WOW64 process"
else
  print "I'm NOT a WOW64 process"
end

function dumptable(T,t)
    print '--------------------------'
    print(T)
    print '--------------------------'
    for k,v in pairs(t)do print(k,v) end
end

if winres then
    dumptable('winres', winres)
    if winres.scripts then
        dumptable('winres.scripts', winres.scripts)
    end
end

for k,v in pairs(winres.scripts) do
    package.preload[k:lower()] = function(...)
        return winres.c_loader(k:upper())
    end
    package.preload[k:upper()] = package.preload[k:lower()]
end
dumptable('package.preload', package.preload)
dumptable('winreg', winreg)
require "helloworld"
dumptable('package.loaded', package.loaded)
