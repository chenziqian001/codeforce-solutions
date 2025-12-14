// 【重要】请将 "YourHandleHere" 替换为你自己的 Codeforces Handle！
const MY_HANDLE = "626856811czq"; 

/**
 * 1. 从 Codeforces API 获取用户的已解决问题集合
 * @param {string} handle - 用户的 Codeforces Handle
 * @returns {Promise<Set<string>>} - 包含所有已通过问题ID（如 '1700A'）的 Set
 */
async function getSolvedProblems(handle) {
    // Codeforces API: user.status 用于获取提交记录
    const url = `https://codeforces.com/api/user.status?handle=${handle}&from=1&verdict=OK`;
    
    try {
        const response = await fetch(url);
        if (!response.ok) {
            throw new Error(`API request failed with status: ${response.status}`);
        }
        
        const data = await response.json();
        
        if (data.status !== "OK") {
            console.error("Codeforces API Error:", data.comment);
            return new Set();
        }
        
        const solved = new Set();
        data.result.forEach(submission => {
            // 通过 Contest ID 和 Index 组合成唯一的问题 ID
            const problemId = submission.problem.contestId + submission.problem.index;
            solved.add(problemId);
        });
        
        return solved;
        
    } catch (error) {
        console.error(`Error fetching data for ${handle}:`, error);
        return new Set();
    }
}

/**
 * 2. 计算两个集合的交集大小
 * @param {Set<string>} setA 
 * @param {Set<string>} setB 
 * @returns {number} 交集大小
 */
function calculateIntersection(setA, setB) {
    let intersectionCount = 0;
    
    // 遍历较小的集合更高效
    const smallerSet = setA.size < setB.size ? setA : setB;
    const largerSet = setA.size < setB.size ? setB : setA;

    smallerSet.forEach(problemId => {
        if (largerSet.has(problemId)) {
            intersectionCount++;
        }
    });
    return intersectionCount;
}

/**
 * 3. 主函数：获取数据，计算并插入结果到页面
 */
async function calculateAndDisplayIntersection() {
    // 检查页面是否加载完成且结构正确
    const handleElement = document.querySelector('.main-info .user-handle');
    if (!handleElement) {
        console.log("Not on a valid profile page.");
        return;
    }

    const friendHandle = handleElement.textContent.trim();
    
    if (friendHandle === MY_HANDLE) {
        // 如果访问的是自己的主页，则不显示交集
        return;
    }

    // 提示用户正在计算
    const targetInfoDiv = document.querySelector('.main-info');
    const loadingDiv = document.createElement('div');
    loadingDiv.innerHTML = `<div style="padding: 10px; margin-top: 10px; border: 1px solid #ddd; background-color: #f0f0f0;">
                                正在计算与 ${MY_HANDLE} 的刷题交集...
                            </div>`;
    targetInfoDiv.after(loadingDiv);

    // 并发获取两个用户的提交数据
    const [mySolved, friendSolved] = await Promise.all([
        getSolvedProblems(MY_HANDLE),
        getSolvedProblems(friendHandle)
    ]);
    
    loadingDiv.remove(); // 移除加载提示
    
    const intersectionCount = calculateIntersection(mySolved, friendSolved);

    // 插入结果到页面
    const resultDiv = document.createElement('div');
    resultDiv.innerHTML = `<div style="padding: 10px; margin-top: 10px; border: 1px solid #0056b3; background-color: #e0f7ff; color: #0056b3;">
                            🤝 共同解决问题数 (与 ${MY_HANDLE})：
                            <strong style="font-size: 1.2em;">${intersectionCount}</strong>
                          </div>`;
    targetInfoDiv.after(resultDiv);
}

// 启动程序
calculateAndDisplayIntersection();