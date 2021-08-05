# TripService

When pairing with some developers, I've noticed that one of the reasons they are not unit testing existing code is because, quite often, they don't know how to overcome certain problems. The most common one is related to hard-wired dependencies - Singletons and static calls.
Let's look at this piece of code:
```
public List<Trip> getTripsByUser(User user) throws UserNotLoggedInException {
    List<Trip> tripList = new ArrayList<Trip>();
    User loggedUser = UserSession.getInstance().getLoggedUser();
    boolean isFriend = false;
    if (loggedUser != null) {
        for (User friend : user.getFriends()) {
            if (friend.equals(loggedUser)) {
                isFriend = true;
                break;
            }
        }
        if (isFriend) {
            tripList = TripDAO.findTripsByUser(user);
        }
        return tripList;
    } else {
        throw new UserNotLoggedInException();
    }
}
```
Horrendous, isn't it? The code above has loads of problems, but before we change it, we need to have it covered by tests.

There are two challenges when unit testing the method above. They are:
```
User loggedUser = UserSession.getInstance().getLoggedUser();  
```
```
tripList = TripDAO.findTripsByUser(user);                   
```
As we know, unit tests should test just one class and not its dependencies. That means that we need to find a way to mock the Singleton and the static call. In general we do that injecting the dependencies, but we have a rule, remember?

We can't change any existing code if not covered by tests. The only exception is if we need to change the code to add unit tests, but in this case, just automated refactorings (via IDE) are allowed.

Besides that, many of the mocking frameworks are not be able to mock static methods anyway, so injecting the TripDAO would not solve the problem.

>@sandromancuso
>http://craftedsw.blogspot.com/2011/07/testing-legacy-hard-wired-dependencies.html
