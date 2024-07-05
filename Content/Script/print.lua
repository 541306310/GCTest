--[[
    说明：在蓝图中实现UnLuaInterface接口，并通过 GetModuleName 指定脚本路径，即可绑定到Lua

    例如：
    本脚本由 "Content/Tutorials/01_HelloWorld/HelloWorld.map" 的关卡蓝图绑定
]]



local M = UnLua.Class()

function M:ReceiveBeginPlay()
    print("年后")

end

function M:SayHi(Name)
    local origin = self.Overridden.SayHi(self, name)
    return origin .. "\n\n" ..
        [[现在我们已经相互熟悉了，这是来自Lua的问候。

        —— 本示例来自 "Content/Script/Tutorials.02_OverrideBlueprintEvents.lua"
    ]]
end

return M