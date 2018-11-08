cd FileMgrCom
& "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" .\FileMgrCom.vcxproj 

cd ..\TextSearchCom
& "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" .\TextSearchCom.vcxproj 

cd ..\Client
& "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\MSBuild\15.0\Bin\MSBuild.exe" .\Client.vcxproj 

cd ..