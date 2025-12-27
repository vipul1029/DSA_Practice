import { CognitoUserPool, CognitoUser, AuthenticationDetails } from 'amazon-cognito-identity-js';

const poolData = { 
    UserPoolId: '<USER_POOL_ID>', 
    ClientId: '<CLIENT_ID>'
};
const userPool = new CognitoUserPool(poolData);

function login(username, password) {
    const user = new CognitoUser({ Username: username, Pool: userPool });
    const authDetails = new AuthenticationDetails({ Username: username, Password: password });
    user.authenticateUser(authDetails, {
        onSuccess: (result) => console.log('Login successful', result),
        onFailure: (err) => console.error(err)
    });
}
